from PIL import ImageGrab
import matplotlib as mpl

def get_color(pil_img):
    img = pil_img.copy()
    img = img.convert("RGBA")
    img = img.resize((1, 1), resample = 0)
    dominant_color = img.getpixel((0,0))
    return dominant_color

run = True

while (run == True):
    image = ImageGrab.grab()
    print('#%02x%02x%02x%02x' % get_color(image))


    
# import serial

# a = 255
# arduino = serial.Serial('com6', 9600)

# arduino.write(a.encode())
