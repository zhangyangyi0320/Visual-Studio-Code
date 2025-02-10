import turtle

def draw_firecracker(x, y, color):
    """ 绘制鞭炮 """
    turtle.penup()
    turtle.goto(x, y)
    turtle.pendown()
    turtle.color(color)
    turtle.begin_fill()
    for _ in range(5):
        turtle.penup()
        turtle.forward(30)
        turtle.pendown()
        turtle.left(60)
        turtle.forward(10)
        turtle.right(120)
        turtle.forward(10)
        turtle.left(60)
        turtle.forward(20)
    turtle.end_fill()

def draw_fu(x, y):
    """ 绘制福字 """
    turtle.penup()
    turtle.goto(x, y)
    turtle.pendown()
    turtle.color("red")
    turtle.width(3)
    turtle.begin_fill()
    turtle.circle(20, steps=4)
    turtle.end_fill()

turtle.setup(800, 600)
turtle.speed(3)
turtle.penup()
turtle.hideturtle()
turtle.bgcolor("black")

# 画天空中的"新春快乐"
turtle.penup()
turtle.goto(0, 200)
turtle.color("yellow")
turtle.write("新春快乐", align="center", font=("Arial", 40, "bold"))

# 画一座房子作为春节的背景
turtle.penup()
turtle.goto(-150, -100)
turtle.pendown()
turtle.color("whitesmoke")
turtle.begin_fill()
for _ in range(4):
    turtle.forward(300)
    turtle.left(90)
turtle.end_fill()

# 画房顶
turtle.penup()
turtle.goto(-170, 200)
turtle.pendown()
turtle.color("red")
turtle.begin_fill()
turtle.goto(170, 200)
turtle.goto(0, 300)
turtle.goto(-170, 200)
turtle.end_fill()

# 画福字
draw_fu(-100, 180)
draw_fu(100, 180)

# 画鞭炮
draw_firecracker(-200, -200, "red")
draw_firecracker(200, -200, "red")

# 画一些星星
turtle.color("white")
turtle.width(2)
for _ in range(50):
    turtle.penup()
    turtle.goto(-300 + 12 * _, -250)
    turtle.pendown()
    turtle.dot(5)

turtle.done()
