 
import os
from random import random
from math import floor 
from time import sleep
import argparse

def get_robot_arg(): # parse the robot string from argument
    parser = argparse.ArgumentParser()
    parser.add_argument("-r", "--robot", help="enter your robot string", default="ZETIN", type=str)
    args = parser.parse_args()
    return args.robot
 

def print_robot(w:int, h:int, x:int, y:int, robot:str): # print the robot string in the terminal
 #   print("\n\n\n\n\n")
    for i in range(h):
        if i == x:
            for j in range(w):
                if j == y:
                    print(robot)
                    break
                else:
                    print(" ", end="") 
        else:
            print() 


def main():

    # get robot string
    robot = get_robot_arg()
    robot_len = len(robot)

    # initialize the robot
    speed_x = 1; speed_y = 1
    x = 0; y = 0;
    max_y = 0; max_x=0

    # the robot swims over your terminal
    try: 
        while True:
            # get the size of your terminal
            (w,h) = tuple(os.get_terminal_size())       
            h -=1
            if w <= robot_len-5 or h <= 5: # teriminal is not enough to swim
                print(f"Unhappy {robot} Has Died ):")
                break
            max_y = w-robot_len-1; max_x=h-1

            # swims
            temp_x = x + speed_x; temp_y = y + speed_y

            # rescue your robot out of the terminal
            if not (0 <= temp_x <= max_x):
                speed_x *= -1;
                temp_x = 0 if temp_x<=0 else max_x
                temp_x += speed_x
            
            if not (0 <= temp_y <= max_y):
                y_dir = -1 if speed_y>0 else 1;
                speed_y = (floor(random()*(robot_len-1))+1) * y_dir
                temp_y = 0 if temp_y<=0 else max_y
                temp_y += speed_y

            # swims ~
            x = temp_x; y = temp_y 
            print_robot(w,h,x,y,robot)
            sleep(0.1)

    except KeyboardInterrupt:
        print(f"\nHappy {robot} Has Fullfilled! (:")

            


if __name__ == "__main__":
    main()
