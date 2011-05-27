import argparse
from bitmaploader import Bitmap
import os
import sys

gridSize = 8
levelWidth = 30
levelHeight = 20

def validateBitmapSize(width, height, bitmap):
	if bitmap.width != width:
		print("error: bitmap must be {0} pixels wide".format(width))
		sys.exit()
	if bitmap.height != height:
		print("error: bitmap must be {0} pixels high".format(height))
		sys.exit()

def loadBlockBitmaps():
	bmps = []
	pathName = os.path.join(os.getcwd(), "blockbmps")

	dirList = os.listdir(pathName)

	for fileName in dirList:
		if os.path.isfile(os.path.join(pathName, fileName)):
			if fileName[-len('bmp'):] == 'bmp':

				bmps.append({'bmp': Bitmap(os.path.join(pathName, fileName)), 'name': fileName[:len(fileName) - len('.bmp')]})

				validateBitmapSize(gridSize, gridSize, bmps[len(bmps) - 1]['bmp'])

	return bmps

def saveLevel(level, width, height, number, name):
	with open(os.path.join(os.getcwd(), "level{0}.h".format(number)), "w") as f:

		f.write("#ifndef _LEVEL{0}_H_\n".format(number))
		f.write("#define _LEVEL{0}_H_\n".format(number))
		f.write("\n")

		f.write("#include \"leveldefinition.h\"\n")
		f.write("#include \"bitmapserver.h\"\n")
		f.write("\n")

		f.write("/**\n")
		f.write(" * Level {0}.\n".format(number))
		f.write(" */\n")
		f.write("class Level{0} : public LevelDefinition ".format(number))
		f.write("{\n")
		f.write("public:\n")
		f.write("\n")

		f.write("\t/**\n")
		f.write("\t * Constructor.\n")
		f.write("\t */\n")
		f.write("\tLevel{0}();\n".format(number))
		f.write("\n")

		f.write("};\n")
		f.write("\n")
		f.write("#endif\n")
		f.write("\n")

	with open(os.path.join(os.getcwd(), "level{0}.cpp".format(number)), "w") as f:

		f.write("#include \"level{0}.h\"\n".format(number))
		f.write("#include \"bitmapserver.h\"\n")

		f.write("const static u8 level{0}Data[600] = ".format(number))
		f.write("{\n")

		for y in range(0, height):
			f.write("\t\t\t")

			for x in range(0, width):
				f.write("{0}".format(level[(y * width) + x]).ljust(2))

				if (y * width) + x < ((height - 1) * width) + (width - 1):
					f.write(",")
				else:
					f.write("};")

			f.write("\n")

		f.write("\n")

		f.write("\tLevel{0}::Level{0}() : LevelDefinition(30, 20, {0}, \"{1}\", level{0}Data, COLOUR_YELLOW, COLOUR_RED, COLOUR_BLUE) ".format(number, name))
		f.write("{\n")
		f.write("}\n")

		f.write("\n")

def compareGridSquareWithBlock(level, block, gridX, gridY):

	for y in range(0, gridSize):
		for x in range(0, gridSize):

			levelX = (gridX * gridSize) + x
			levelY = (gridY * gridSize) + y

			if level.get_pixel_red(levelX, levelY) != block.get_pixel_red(x, y):
				return False
			if level.get_pixel_green(levelX, levelY) != block.get_pixel_green(x, y):
				return False
			if level.get_pixel_blue(levelX, levelY) != block.get_pixel_blue(x, y):
				return False

	return True

parser = argparse.ArgumentParser(description="converts screenshots of Earth Shaker maps into level definition classes")
parser.add_argument('bmp', help='bmp file containing level layout')
parser.add_argument('number', help='number of the level')
parser.add_argument('name', help='name of the level')

args = parser.parse_args()

# Load the level bitmap
levelBmp = Bitmap(args.bmp)
validateBitmapSize(gridSize * levelWidth, gridSize * levelHeight, levelBmp)

# Load the block bitmaps
blockBmps = loadBlockBitmaps()

levelLayout = []

# Loop through blocks in level
for gridY in range(0, levelHeight):
	for gridX in range(0, levelWidth):

		foundBlock = False

		# Loop through block bitmaps
		for block in blockBmps:

			# Compare this grid with the block bitmap
			if compareGridSquareWithBlock(levelBmp, block['bmp'], gridX, gridY):

				levelLayout.append(block['name'])
				foundBlock = True
				break

		if not foundBlock:
			sys.exit("error: block does not exist for grid {0}, {1}".format(gridX, gridY))
		
saveLevel(levelLayout, levelWidth, levelHeight, args.number, args.name)