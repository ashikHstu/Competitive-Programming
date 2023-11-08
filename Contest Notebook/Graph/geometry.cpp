Geometry :
Circle :
Chord length=sqrt(2*r*r*(1-cos(alpha))) = 2*r*sin(alpha/2)
Sector = (alpha/360.0)*A ; here, A=area of circle
Area of a circular ring inside with radius :  area  = π (R^2 – r^2 )
 Sector angle of a circle alpha = (180 x  s )/ (π r ).
Triangle :
Incircle radius , r=A/s;
Circumscribed circle radius, R=(a*b*c)/(4*A)
(cosine rule) Angle , γ = acos(( a^2+b^2-c^2)/(2*a*b))
(sine rule) a/(sinα) = a/(sinβ) = c/(sinγ) = 2R
Area of an equilateral triangle = (√3)/4 × side^2
Area of an isosceles triangle  =(¼*(b*sqrt(4*a*a-b*b))
double angle(point a, point o, point b) // returns angle aob in rad
{
    vec oa = toVec(o, a), ob = toVec(o, b);
    return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob)));
}

