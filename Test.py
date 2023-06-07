import time
from PIL import Image, ImageDraw, ImageFont
import Adafruit_SSD1306
import board

# OLED display configuration
DISPLAY_WIDTH = 128
DISPLAY_HEIGHT = 64
DISPLAY_ADDRESS = 0x3C

# Initialize the I2C bus
i2c = board.I2C()
display = Adafruit_SSD1306.SSD1306_I2C(DISPLAY_WIDTH, DISPLAY_HEIGHT, i2c, addr=DISPLAY_ADDRESS)

# Create a blank image with a black background
image = Image.new("1", (DISPLAY_WIDTH, DISPLAY_HEIGHT))
draw = ImageDraw.Draw(image)
font = ImageFont.load_default()

# Function to display a message on the OLED display
def display_message(message):
    # Clear the image buffer
    draw.rectangle((0, 0, DISPLAY_WIDTH, DISPLAY_HEIGHT), outline=0, fill=0)

    # Draw the message
    draw.text((0, 0), message, font=font, fill=255)

    # Display the image
    display.image(image)
    display.show()

# Main loop
if __name__ == '__main__':
    try:
        while True:
            message = "Hello, OLED!"
            display_message(message)
            time.sleep(5)  # Delay between updates

    except KeyboardInterrupt:
        display.fill(0)
        display.show()
