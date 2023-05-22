from PIL import ImageGrab
from serial import Serial
import time

arduino = Serial("com6", 9600)


def get_color(img):
    img = img.convert("RGBA")
    img = img.resize((1, 1), resample=0)
    dominant_color = img.getpixel((0, 0))
    return dominant_color


run = True

while run:
    try:
        image = ImageGrab.grab()
        pyinput = "%02x%02x%02x%02x" % get_color(image)
        pyinput = pyinput[:6] + "\r"
        print(pyinput)
        arduino.write(pyinput.encode())
        image.close()
        time.sleep(0.1)
    except KeyboardInterrupt:
        run = False
        arduino.close()
