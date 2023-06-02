import mediapipe as mp
import numpy as np
import cv2


WaitingForResult = []
Password = []
PasswordS = []
cap = cv2.VideoCapture(0)
mp_hands = mp.solutions.hands
hands = mp_hands.Hands()
mpdraw = mp.solutions.drawing_utils
finger_Coord = [(8, 6), (12, 10), (16, 14), (20, 18)]
thumb_Coord = (4,2)
while True:
    success, frame = cap.read()
    RGB_image = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
    result = hands.process(RGB_image)
    multiLandMarks = result.multi_hand_landmarks
    if multiLandMarks:
        handList = []
        for HandLms in multiLandMarks:
            mpdraw.draw_landmarks(frame, HandLms, mp_hands.HAND_CONNECTIONS)
            for idx, lm in enumerate(HandLms.landmark):
                    h, w, c = frame.shape
                    cx, cy = int(lm.x * w), int(lm.y * h)
                    handList.append((cx, cy))
        for point in handList:
            cv2.circle(frame, point, 10, (255, 255, 0), cv2.FILLED)
        upCount = 0
        for coordinate in finger_Coord:
            if handList[coordinate[0]][1] < handList[coordinate[1]][1]:
                upCount += 1
        if handList[thumb_Coord[0]][0] > handList[thumb_Coord[1]][0]:
            upCount += 1
        cv2.putText(frame, str(upCount), (150,150), cv2.FONT_HERSHEY_PLAIN, 12, (0,255,0), 12)
        cv2.imshow("Counting number of fingers", frame)
        if (upCount >=0):
            WaitingForResult.append(0)
            if (len(WaitingForResult)==40):
                Password.append(upCount)
                print(upCount)
                WaitingForResult = []
        
        if (len(Password)==5):
            file = open("Password.txt", "r")
            rs = file.read()
            for i in Password:
                PasswordS.append(str(i))
            s = ''.join(PasswordS)
            if (rs == s):
                print('The code you should use is: 122199')
                Password = []
        cv2.waitKey(1)
