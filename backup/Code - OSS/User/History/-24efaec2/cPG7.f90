
program name
  implicit none
  real::x,y,h
  real::k1,k2,k3,k4
  x=0
  y=1
  h=0.1
  k1=h*f(x,y)
end program name

contains
function f(x,y) result(m)
  implicit none
  real::x,y
  real::m
  m=x+y
end function f