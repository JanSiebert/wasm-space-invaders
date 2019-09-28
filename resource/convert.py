from PIL import Image

colors = [
	0xff000000,
	0xff555555,
	0xffaaaaaa,
	0xffffffff,
	0xff5555ff,
	0xff0000aa,
	0xff0055aa,
	0xff55ffff,
	0xff55ff55,
	0xff00aa00,
	0xffffff55,
	0xffaaaa00,
	0xffff55ff,
	0xffff5555,
	0xffaa00aa,
	0xffaa0000
]

palette = {
	(
		(c>>0)&255, 
		(c>>8)&255,
		(c>>16)&255
	): i for i, c in enumerate(colors)
}

def toColorIndex(c):
	return palette[c]

img = Image.open("sprites.png")
# print("loaded image ({}x{})".format(*img.size))
pixmap = img.load()
width = img.size[0]
height = img.size[1]
data = []
for y in range(height):
	for x in range(0,width,2):
		p1 = toColorIndex(pixmap[x, y])
		p2 = toColorIndex(pixmap[x+1, y])
		c = (p1 << 4) | p2
		data.append(hex(c))

print(', '.join(data))

