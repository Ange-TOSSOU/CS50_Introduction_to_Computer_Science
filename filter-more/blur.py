from PIL import Image, ImageFilter

before = Image.open("images/stadium.bmp")
after = before.filter(ImageFilter.BoxBlur(2))
after.save("out.bmp")
