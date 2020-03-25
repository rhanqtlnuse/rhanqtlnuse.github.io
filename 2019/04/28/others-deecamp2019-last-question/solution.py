from PIL import Image
import torchvision.transforms as transforms

img = Image.open('number_matrix.bmp')
img = transforms.ToTensor()(img).squeeze()

img_height, img_width = img.shape

HEIGHT, WIDTH = 28, 28

def equals(a, b):
    return (a == b).sum().item() == HEIGHT * WIDTH

def increment(L, key):
    not_found = True
    for k in range(len(L)):
        key, val = L[k]
        if equals(piece, key):
            L[k] = (key, val + 1)
            not_found = False
            break
    if not_found:
        L.append((piece, 1))

print('Collecting...')
L = []
for i in range(img_height // HEIGHT):
    x = i * HEIGHT
    for j in range(img_width // WIDTH):
        y = j * WIDTH
        piece = img[x: x + HEIGHT, y: y + WIDTH]
        increment(L, piece)
print('Done!')

transform = transforms.ToPILImage()
total = 0
for key, val in L:
    piece = key.unsqueeze(0)
    transform(piece).show()
    digit = int(input('>>> '))
    total += digit * val
print('Total:', total)
