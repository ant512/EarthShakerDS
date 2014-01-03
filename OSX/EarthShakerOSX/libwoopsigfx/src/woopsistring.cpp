#include <ctype.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include "stringiterator.h"
#include "woopsistring.h"

using namespace WoopsiGfx;

WoopsiString::WoopsiString() {
	init();
}

WoopsiString::WoopsiString(const char* text) {
	init();
	setText(text);
}

WoopsiString::WoopsiString(const u32 text) {
	init();
	setText(text);
}

WoopsiString::WoopsiString(const WoopsiString& string) {
	init();
	setText(string);
}

WoopsiString::WoopsiString(const WoopsiString& string, const s32 startIndex) {
	init();
	setText(string, startIndex, string.getLength());
}

WoopsiString::WoopsiString(const WoopsiString& string, const s32 startIndex, const s32 length) {
	init();
	setText(string, startIndex, length);
}

void WoopsiString::init() {
	_text = NULL;
	_dataLength = 0;
	_stringLength = 0;
	_allocatedSize = 0;
	_growAmount = 32;
}

WoopsiString& WoopsiString::operator=(const WoopsiString& string) {
	if (&string != this) {
		setText(string);
	}
	
	return *this;
}

WoopsiString& WoopsiString::operator=(const char* string) {
	setText(string);
	return *this;
}

WoopsiString& WoopsiString::operator=(const u32 letter) {
	setText(letter);
	return *this;
}

WoopsiString& WoopsiString::operator+=(const WoopsiString& string) {
	append(string);
	
	return *this;
}

WoopsiString WoopsiString::operator+(const WoopsiString& string) {
	WoopsiString str = *this;
	str.append(string);
	
	return str;
}

StringIterator* WoopsiString::newStringIterator() const {
	return new StringIterator(this);
}

void WoopsiString::setText(const WoopsiString& text, const s32 startIndex, const s32 length) {

	StringIterator* iterator = text.newStringIterator();
	if (!iterator->moveTo(startIndex)) return;

	// Build up the string character by character.  This is slower than
	// a straightforward memcpy(), but it avoids multiple calls to getToken().
	// The difference in speed between this method and a more long-winded, lower
	// level approach is probably minimal.  This method gets bounds checking for
	// free.
	s32 count = 0;
	while (count < length) {
		append(iterator->getCodePoint());
		if (!iterator->moveToNext()) break;
		count++;
	}

	delete iterator;
}

void WoopsiString::setText(const WoopsiString& text) {

	// Ensure we've got enough memory available
	allocateMemory(text.getByteCount(), false);

	memcpy(_text, text.getCharArray(), text.getByteCount());

	_dataLength = text.getByteCount();
	_stringLength = text.getLength();
}

void WoopsiString::setText(const char* text) {

	s32 length = (s32)strlen(text);

	// Ensure we've got enough memory available
	allocateMemory(length, false);

	// Copy/filter the valid UTF-8 tokens into _text and cache the length
	s32 unicodeChars = 0;
	_dataLength = filterString(_text, text, length, &unicodeChars);
	_stringLength = unicodeChars;
}

void WoopsiString::setText(const u32 codePoint) {

	// Encode the character
	u8 numBytes = 0;
	const char* encoded = encodeCodePoint(codePoint, &numBytes);

	// Is the codepoint valid?
	if (encoded != NULL) {

		// Ensure we've got enough memory available
		allocateMemory(numBytes, false);
	
		// Copy the valid UTF-8 token into _text and cache the length
		memcpy(_text, encoded, numBytes);
		
		_dataLength = numBytes;
		_stringLength = 1;
	
		delete[] encoded;
	} else {
		
		// Codepoint is invalid; we just need to truncate the string
		_dataLength = 0;
		_stringLength = 0;
	}
}

void WoopsiString::append(const WoopsiString& text) {

	// Ensure we've got enough memory available
	allocateMemory(_dataLength + text.getByteCount(), true);

	memcpy(_text + _dataLength, text.getCharArray(), text.getByteCount());

	_dataLength += text.getByteCount();
	_stringLength += text.getLength();
}

char* WoopsiString::getToken(s32 index) const {
        
	// Early exit if the string is empty
	if (!hasData()) return NULL;

	// Early exit if we want the entire string
	if (index == 0) return _text;

	// Early exit if the index is greater than the length of the string
	if (index >= _stringLength) return NULL;

	char token;
	char* pos = _text;

	while (index > 0) {

		pos++;
		token = *pos;

		if ((token < 0x80) || ((token > 0xC2) && (token < 0xFE))) {
			if (index <= 1) return pos;
			index--;
		}
	}

	// No corresponding token found
	return NULL;
}

void WoopsiString::insert(const WoopsiString& text, s32 index) { 

	// Early exit if the string is empty
	if (!hasData()) {
		WoopsiString::setText(text);
		return;
	}

	// Early exit if we're just appending
	if (index >= _stringLength) {
		WoopsiString::append(text);
		return;
	}

	// Locate the point at which we can cut the existing string 
	s32 insertPoint = (s32)(getToken(index) - _text);

	// Get the total size of the string that we need
	s32 newSize = _dataLength + text.getByteCount();

	// Reallocate memory if the existing memory isn't large enough
	if (_allocatedSize < newSize) {
		
		newSize += _growAmount;

		// Allocate new string large enough to contain additional data
		char* newText = new char[newSize];

		// Copy the start of the existing text to the newly allocated string
		if (insertPoint > 0) memcpy(newText, _text, insertPoint);

		// Insert the additional text into the new string
		u32 size = text.getByteCount();
		
		memcpy(newText + insertPoint, text.getCharArray(), size);
		_stringLength += text.getLength();

		// Copy the end of the existing text the the newly allocated string
		if (_dataLength > insertPoint) memcpy(newText + insertPoint + size, _text + insertPoint, _dataLength - insertPoint);

		_allocatedSize = newSize;

		// Delete existing string
		delete[] _text;

		// Swap pointers 
		_text = newText;				
		_dataLength += size;
	} else {

		// Existing size large enough, so make space in string for insert
		for (s32 i = 0; i < _dataLength - insertPoint; ++i) {
			_text[newSize - i - 1] = _text[_dataLength - i - 1];
		}

		// Insert the additional text into the new string
		memcpy(_text + insertPoint, text.getCharArray(), text.getByteCount());

		_dataLength += text.getByteCount();
		_stringLength += text.getLength();
	}
}

void WoopsiString::remove(const s32 startIndex) {

	// Reject if requested operation makes no sense
	if (!hasData()) return;
	if (startIndex >= _stringLength) return;
	if (_dataLength == 0) return;

	// Find the UTF-8 token corresponding to startIndex        
	char* pos = getToken(startIndex);

	// Abort if unable to find index
	if (pos == NULL) return;
        
	// Removing characters from the end of the string is trivial - simply
	// decrease the length
	_dataLength = (s32)(pos - _text);

	_stringLength -= (_stringLength - startIndex);
}

void WoopsiString::remove(const s32 startIndex, const s32 count) {

	// Reject if requested operation makes no sense
	if (!hasData()) return;
	if (startIndex >= _stringLength) return;
	if (_dataLength == 0) return;

	// Use alternative remove method if end point matches or exceeds the
	// size of the string.  The other method is much faster
	if (startIndex + count >= _stringLength) {
		remove(startIndex);
		return;
	}

	// Find the utf-8 token corresponding to startIndex
	char* startPos = getToken(startIndex);

	// Abort if unable to start point
	if (startPos == NULL) return;

	// Find the utf-8 token corresponding to startIndex + count
	char* endPos = getToken(startIndex + count);

	// Abort if unable to find end point
	if (endPos == NULL) while(1) { };//return;

	// Copy characters from a point after the area to be deleted into the space created
	// by the deletion
	if (startPos < endPos) memmove(startPos, endPos, _dataLength - u32(endPos - _text));
	
	// Decrease length
	_dataLength -= (endPos - startPos);

	_stringLength -= count;
}

const u32 WoopsiString::getCharAt(s32 index) const {
	if (index < 0) return 0;
	if (index >= getLength()) return 0;
	
	const char* token = getToken(index);
	return getCodePoint(token, NULL);
}

const s32 WoopsiString::indexOf(u32 letter) const {
	return indexOf(letter, 0, getLength());
}

const s32 WoopsiString::indexOf(u32 letter, s32 startIndex) const {
	return indexOf(letter, startIndex, getLength() - startIndex);
}

const s32 WoopsiString::indexOf(u32 letter, s32 startIndex, s32 count) const {

	// Exit if no data available
	if (!hasData()) return -1;

	s32 index = -1;
	s32 charsExamined = 0;

	StringIterator* iterator = newStringIterator();
	if (!iterator->moveTo(startIndex)) return -1;

	do {
		if (iterator->getCodePoint() == letter) {
			index = iterator->getIndex();
			break;
		}

		charsExamined++;
	} while (iterator->moveToNext() && (charsExamined < count));

	delete iterator;

	return index;
}

const s32 WoopsiString::lastIndexOf(u32 letter) const {
	return lastIndexOf(letter, getLength() - 1, getLength());
}

const s32 WoopsiString::lastIndexOf(u32 letter, s32 startIndex) const {
	return lastIndexOf(letter, startIndex, getLength() - (getLength() - startIndex));
}

const s32 WoopsiString::lastIndexOf(u32 letter, s32 startIndex, s32 count) const {

	// Exit if no data available
	if (!hasData()) return -1;

	s32 index = -1;
	s32 charsExamined = 0;

	StringIterator* iterator = newStringIterator();
	if (!iterator->moveTo(startIndex)) return -1;

	do {
		if (iterator->getCodePoint() == letter) {
			index = iterator->getIndex();
			break;
		}

		charsExamined++;
	} while (iterator->moveToPrevious() && (charsExamined <= count));

	delete iterator;

	return index;
}

WoopsiString WoopsiString::subString(s32 startIndex) const {
	return WoopsiString(*this, startIndex, getLength() - startIndex);
}

WoopsiString WoopsiString::subString(s32 startIndex, s32 length) const {
	return WoopsiString(*this, startIndex, length);
}

void WoopsiString::allocateMemory(s32 chars, bool preserve) {

	// Do we already have enough memory allocated to contain this new size?
	// If so, we can avoid deallocating and allocating new memory by re-using
	// the old
	
	if (chars > _allocatedSize) {

		// Not enough space in existing memory; allocate new memory
		char* newText = new char[chars + _growAmount];

		// Free old memory if necessary
		if (_text != NULL) {

			// Preserve existing data if required
			if (preserve) memcpy(newText, _text, _dataLength);

			delete[] _text;
		}

		// Swap pointer to new memory
		_text = newText;

		// Remember how much memory we've allocated
		_allocatedSize = chars + _growAmount;
	}
}

void WoopsiString::copyToCharArray(char* buffer) const {
	memcpy(buffer, _text, _dataLength);
	buffer[_dataLength] = '\0';
}

s32 WoopsiString::filterString(char* dest, const char* src, s32 sourceBytes, s32* totalUnicodeChars) const {
	u8 bytes;
	s32 totalBytes = 0;

	while (totalBytes < sourceBytes) {
		getCodePoint(src, &bytes);

		if (bytes == 0) {

			// This utf-8 token is corrupt; ignore the first char and find a new
			// utf-8 token
			src++;
		} else {

			// Copy the valid utf-8 tokens
			memcpy(dest, src, bytes);
			totalBytes += bytes;
			*totalUnicodeChars += 1;
			src += bytes;
			dest += bytes;
		}
	}

	return totalBytes;
}

u32 WoopsiString::getCodePoint(const char* string, u8* numChars) const {
	char char0 = *string;

	if (numChars) *numChars = 0;

	// 0xxxxxxx ASCII char
	if (char0 < 0x80) {
		if (numChars) *numChars = 1;
		return char0;
	}

	// 1xxxxxxx 10xxxxxx
	if ((string[1] < 0x80) || (string[1] >= 0xC0)) return 0; 

	// 110xxxxx 10xxxxxx
	if (char0 < 0xE0) {
		if (char0 < 0xC2) return 0; // 10xxxxxx (invalid leading char) or  1100000x 10xxxxxx (invalid representation : should have been coded with just 1 char)
		if (numChars) *numChars = 2;
		return ((char0 - 0xC0) << 6) | (string[1] - 0x80); 
	}

	// 111yyyyy 10xxxxxx 10xxxxxx
	if ((string[2]<0x80) || (string[2] >= 0xC0)) return 0; 
	
	// 1110xxxx 10xxxxxx 10xxxxxx
	if (char0 < 0xF0) {
		if ((char0 == 0xE0) && (string[1] < 0xA0)) return 0; // 11100000 100xxxxx 10xxxxxx (invalid representation : should have been coded with at most 2 chars)
		if (numChars) *numChars = 3;
		return ((char0 - 0xE0) << 12) | ((string[1] - 0x80) << 6) | (string[2] - 0x80); 
	}

	// There shouldn't be many utf-8 tokens beyond this point

	// 1111yyyy 10xxxxxx 10xxxxxx 10xxxxxx
	if ((string[3] < 0x80) || (string[3] >= 0xC0)) return 0; 

	// 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
	if (char0 < 0xF8) {
		if ((char0 == 0xF0) && (string[1]<0x90)) return 0; // 11110000 1000xxxx 10xxxxxx 10xxxxxx  (invalid representation : should have been coded with at most 3 chars)
		if (numChars) *numChars = 4;
		return ((char0 - 0xF0) << 18) | ((string[1] - 0x80) << 12) | ((string[2] - 0x80) << 6) | (string[3] - 0x80);
	}            

	// 11111yyy 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx
	if ((string[4] < 0x80) || (string[4] >= 0xC0)) return 0; 

	// 111110xx 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx
	if (char0 < 0xFC) {
		if ((char0 == 0xF8) && (string[1]<0x88)) return 0; // 11111000 10000xxx 10xxxxxx 10xxxxxx 10xxxxxx (invalid representation : should have been coded with at most 4 chars)
		if (numChars) *numChars = 5;
		return ((char0-0xF8)<<24) | ((string[1]-0x80)<<18) | ((string[2]-0x80)<<12) | ((string[3]-0x80)<<6) | (string[4] -0x80);
	}   

	// 111111yy 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx
	if ((string[5] < 0x80) || (string[5] >= 0xC0)) return 0; 

	// 1111110x 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx
	if (char0 < 0xFE) {
		if ((char0 == 0xFC) && (string[1]<0x84)) return 0; // 11111100 100000xx 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx (invalid representation : should have been coded with at most 5 chars)
		if (numChars) *numChars = 6;
		return ((char0-0xFC)<<30) | ((string[1]-0x80)<<24) | ((string[2]-0x80)<<18) | ((string[3]-0x80)<<12) | ((string[4]-0x80)<<6) | (string[5] -0x80);
	}   

	// 11111110 and 11111111 are invalid
	return 0;
}

const char* WoopsiString::encodeCodePoint(u32 codepoint, u8* numBytes) const {
	
	if (numBytes) *numBytes = 0;
	
	if (codepoint < 0x80) {
		if (numBytes) *numBytes = 1;
		char* buffer = new char[1];
		buffer[0] = codepoint;
		return buffer;
	}

	if (codepoint < 0x0800) {
		if (numBytes) *numBytes = 2;
		char* buffer = new char[2];
		buffer[0] = (codepoint >> 6) + 0xC0;
		buffer[1] = (codepoint & 0x1F) + 0x80;
		return buffer;
	}

	if (codepoint < 0x10000) {
		if (numBytes) *numBytes = 3;
		char* buffer = new char[3];
		buffer[0] = (codepoint >> 12) + 0xE0;
		buffer[1] = ((codepoint >> 6) & 0x3F) + 0x80;
		buffer[2] = (codepoint & 0x3F) + 0x80;
		return buffer;
	}
	
	if (codepoint < 0x10FFFF) {
		if (numBytes) *numBytes = 4;
		char* buffer = new char[4];
		buffer[0] = (codepoint >> 18) + 0xF0;
		buffer[1] = ((codepoint >> 12) & 0x3F) + 0x80;
		buffer[2] = ((codepoint >> 6) & 0x3F) + 0x80;
		buffer[3] = (codepoint & 0x3F) + 0x80;
		return buffer;
	}

	// No legal codepoints after this point
	return NULL;
}

s8 WoopsiString::compareTo(const WoopsiString& string, bool caseSensitive) const {
	
	StringIterator* iterator1 = newStringIterator();
	StringIterator* iterator2 = string.newStringIterator();
	
	u32 codePoint1;
	u32 codePoint2;

	// Get the length of the shortest string
	u32 length = getLength() < string.getLength() ? getLength() : string.getLength();
	
	// Iterate over the string length that both strings possess and check for
	// differences.
	for (u32 i = 0; i < length; ++i) {
		codePoint1 = iterator1->getCodePoint();
		codePoint2 = iterator2->getCodePoint();
		
		// If we are ignoring case, we can adjust any upper-case letters so that
		// they are treated as their lower-case variant by adding a constant.
		if (!caseSensitive) {
			if (isupper(codePoint1)) codePoint1 += 0x20;
			if (isupper(codePoint2)) codePoint2 += 0x20;
		}

		// We cheat a little here to get a passable natural sort.  Numbers will
		// automatically be sorted before text due to the fact that they come
		// first in the ASCII table.  When we hit two numbers at the same point
		// in the strings, though, we can convert the digit sequences to ints
		// and compare those.
		if (isdigit(codePoint1) && isdigit(codePoint2)) {

			u32 charCount1 = 0;
			u32 charCount2 = 0;

			codePoint1 = iterator1->getInteger(&charCount1);
			codePoint2 = iterator2->getInteger(&charCount2);

			if (codePoint1 != codePoint2) {
				delete iterator1;
				delete iterator2;
				
				return codePoint1 > codePoint2 ? 1 : -1;
			}

			// Stop iterating if we hit the end of either string
			if (!iterator1->moveTo(iterator1->getIndex() + charCount1) ||
				!iterator2->moveTo(iterator2->getIndex() + charCount2)) break;
		} else {
	    
			if (codePoint1 != codePoint2) {
				delete iterator1;
				delete iterator2;
				
				return codePoint1 > codePoint2 ? 1 : -1;
			}
			
			// We can potentially hit the end of a string early if we
			// encountered a run of digits at any point - we will have consumed
			// and compared
			// multiple characters in a single iteration.  In that situation we
			// need to exit the loop early.
			if (!iterator1->moveToNext() || !iterator2->moveToNext()) break;
		}
	}
	
	delete iterator1;
	delete iterator2;
	
	// Strings are identical so far, so compare based on string length.  Shorter
	// string comes first
	if (getLength() == string.getLength()) return 0;
	if (getLength() < string.getLength()) return -1;
	
	return 1;
}

s32 WoopsiString::indexOf(const char* text) const {
	return indexOf(text, 0, getLength());
}

s32 WoopsiString::indexOf(const char* text, s32 startIndex) const {
	return indexOf(text, startIndex, getLength() - startIndex);
}

s32 WoopsiString::indexOf(const WoopsiString& text, s32 startIndex, s32 count) const {

	// Exit if no data available
	if (!hasData()) return -1;
	if (!text.hasData()) return -1;

	s32 index = -1;
	s32 charsExamined = 0;
	
	StringIterator* srciter = newStringIterator();
	StringIterator* finditer = text.newStringIterator();
	
	if (!srciter->moveTo(startIndex)) return -1;

	do {
		bool equal = true;
		s32 idx = srciter->getIndex();

		finditer->moveToFirst();
		
		do {
			if (srciter->getCodePoint() != finditer->getCodePoint()) {
				equal = false;
				break;
			}
		} while (finditer->moveToNext() && srciter->moveToNext());

		if (!srciter->moveTo(idx)) break;
		
		if(equal && !finditer->moveToNext()) {
			index = srciter->getIndex();
			break;
		}
		
		charsExamined++;
	} while (srciter->moveToNext() && (charsExamined < count));
	
	
	delete srciter;
	delete finditer;
	
	return index;
}

s32 WoopsiString::lastIndexOf(const char* text) const {
	return lastIndexOf(text, getLength() - 1, getLength());
}

s32 WoopsiString::lastIndexOf(const char* text, s32 startIndex) const {
	return lastIndexOf(text, startIndex, getLength() - (getLength() - startIndex));
}

s32 WoopsiString::lastIndexOf(const WoopsiString& text, s32 startIndex, s32 count) const {

	// Exit if no data available
	if (!hasData()) return -1;
	if (!text.hasData()) return -1;

	s32 index = -1;
	s32 charsExamined = 0;

	StringIterator* srciter = newStringIterator();
	StringIterator* finditer = text.newStringIterator();
	if (!srciter->moveTo(startIndex)) return -1;

	do {
		bool equal = true;
		s32 idx = srciter->getIndex();
				
		finditer->moveToLast();
				
		do {
			if (srciter->getCodePoint() != finditer->getCodePoint()) {
				equal = false;
				break;
			}
		} while (finditer->moveToPrevious() && srciter->moveToPrevious());

		if (!srciter->moveTo(idx)) break;
				
		if(equal && !finditer->moveToPrevious()) {
			index = srciter->getIndex() - text.getLength() + 1;
			break;
		}
				
		charsExamined++;
	} while (srciter->moveToPrevious() && (charsExamined <= count));

	delete srciter;
	delete finditer;
	
	return index;
}

void WoopsiString::format(const char *format, ...) {
	va_list args;
	va_start(args, format);
	this->format(format, args);
	va_end(args);
}

void WoopsiString::format(const char *format, va_list args) {

	// Do the format once to get the length.
	char ch;
	s32 len = vsnprintf(&ch, 1, format, args);

	if (len < 1) {
		setText("");
	} else {

		// Allocate with malloc to prevent us from overflowing the DS' tiny
		// stack
		char* buffer = new char[len + 1];

		// Format again; this time the buffer is guaranteed to be large enough
		// (unless malloc failed, in which case we're stuck anyway)
		vsnprintf(buffer, len + 1, format, args);

		setText(buffer);

		delete[] buffer;
	}
}

void WoopsiString::replace(const WoopsiString& oldText, const WoopsiString& newText) {
	replace(oldText, newText, 0, -1);
}

void WoopsiString::replace(const WoopsiString& oldText, const WoopsiString& newText, const s32 startIndex) {
	replace(oldText, newText, startIndex, -1);
}

void WoopsiString::replace(const s32 startIndex, const s32 count, const WoopsiString& newText) {

	// This is inefficient as it involves an awful lot of seeking through the
	// string.  However, it is good enough for the limited amount of use this
	// method should get.
	remove(startIndex, count);
	insert(newText, startIndex);
}

void WoopsiString::replace(const WoopsiString& oldText, const WoopsiString& newText, const s32 startIndex, const s32 replaceCount) {
	s32 count = replaceCount;
	s32 startPos = startIndex;
	s32 endPos;

	while (count != 0 && (endPos = indexOf(oldText, startPos, getLength() - startPos)) != -1) {
		replace(endPos, oldText.getLength(), newText);
		startPos = endPos + newText.getLength();

		if(count!=-1) count--;
	}
}

void WoopsiString::split(const WoopsiString& separator, WoopsiArray<WoopsiString>& result) const {
	split(separator, true, result);
}

void WoopsiString::split(const WoopsiString& separator, bool allowEmptyEntries, WoopsiArray<WoopsiString>& result) const {
	result.clear();

	s32 startPos = 0;
	s32 endPos;

	while ((endPos = indexOf(separator, startPos, getLength() - startPos)) != -1) {
		if (allowEmptyEntries || startPos != endPos) {
			result.push_back(subString(startPos, endPos - startPos));
		}

		startPos = endPos + separator.getLength();
	}

	if (allowEmptyEntries || startPos != getLength()) {
		result.push_back(subString(startPos));
	}
}
