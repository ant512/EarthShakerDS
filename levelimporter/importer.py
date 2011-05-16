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

def printLevel(level, width, height):
	print("\t\tu8 layout[600] = {")

	for y in range(0, height):
		print("\t\t\t", end="")

		for x in range(0, width):
			print("{0}".format(level[(y * width) + x]).ljust(2), end="")

			if (y * width) + x < ((height - 1) * width) + (width - 1):
				print(",", end="")
			else:
				print("};", end="")

		print('')

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

parser = argparse.ArgumentParser(description="BitBucket-backed bug tracker")
parser.add_argument('levelbmp', help='bmp file containing level layout')

args = parser.parse_args()

# Load the level bitmap
levelBmp = Bitmap(args.levelbmp)
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
		
printLevel(levelLayout, levelWidth, levelHeight)