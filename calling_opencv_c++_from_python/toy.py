import pysomemodule

import cv2
import numpy as np
foo = pysomemodule.ABC("") # This will create an instance of ABC

image = np.matrix([[20,2], [26,30]])

processed_image = foo.doSomething(image)
print(processed_image.shape)

cv2.imwrite('processed.png', processed_image)
