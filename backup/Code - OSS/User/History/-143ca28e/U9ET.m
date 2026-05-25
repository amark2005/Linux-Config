x=2.5
y=5
h=0.1


while x<3
  slope=x+y;
  y=y+h*slope;
  x=x+h;

  printf("x=%.1f , y=%.4f\n",x,y);
end