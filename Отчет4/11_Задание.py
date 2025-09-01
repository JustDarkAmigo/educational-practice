import cv2
import numpy as np

image = cv2.imread("2.png")
if image is None:
    print("Ошибка: Не удалось загрузить изображение.")
else:
    blurred_image = cv2.GaussianBlur(image, (11, 11), 0)
    hsv_image = cv2.cvtColor(blurred_image, cv2.COLOR_BGR2HSV)
    hsv_min = np.array((0, 25, 25), np.uint8)
    hsv_max = np.array((180, 255, 255), np.uint8)
    mask = cv2.inRange(hsv_image, hsv_min, hsv_max)
    contours, _ = cv2.findContours(mask.copy(), cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

    if not contours:
        print("Ошибка:Нет объектов на изображении.")
    else:
        largest_contour = max(contours, key=cv2.contourArea)
        x, y, w, h = cv2.boundingRect(largest_contour)
        center_x = x + w // 2
        center_y = y + h // 2

        # Рисуем прямоугольник, который полностью охватывает фигуру
        cv2.rectangle(image, (x, y), (x + w, y + h), (0, 0, 255), 2)
        cv2.circle(image, (center_x, center_y), 5, (0, 0, 255), -1)

        print(f"Центр прямоугольника: ({center_x}, {center_y})")
        print(f"контур: x={x}, y={y}, width={w}, height={h}")
        cv2.imshow('Result', image)
        cv2.waitKey(0)
        cv2.destroyAllWindows()
