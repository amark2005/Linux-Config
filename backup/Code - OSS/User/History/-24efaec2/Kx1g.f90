
program name
  implicit none
  real::x,y,h
  x=15
  y=1200
  h=0.1
  print *,"y(0.1)= ",rk4(x,y,h)
  contains
    function rk4(x,y,h) result(rk)
      real::x,y,h,rk
      real::k1,k2,k3,k4
      k1=h*f(x,y)
      k2=h*f(x+h/2,y+k1/2)
      k3=h*f(x+h/2,y+k2/2)
      k4=h*f(x+h,y+k3)
      rk=y+(k1+(2*k2)+(2*k3)+k4)/6
    end function rk4
    function f(x,y) result(m)
      real::x,y
      real::m
      m=x+y
    end function f

end program name