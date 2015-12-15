camera
{
   location <0,0,0>
   look_at <1000,0,0>
}

light_source { <1000,1500,0>
		color rgb<1,1,1>
}

cylinder_42 { <4000,0,1000>, <0,1,1>, 100 // coord, direction, rayon
         pigment { color rgb <0,0,1> }
         finish {specular 1}
}

cylinder_42 { <4000,0,1000>, <0,-1,1>, 100 // coord, direction, rayon
         pigment { color rgb <0,1,0> }
         finish {specular 1}
}

sphere { <2000,0,100>, 400 // coord centre et rayon
         pigment { color rgb <1,0,0> }
         finish {transparence 0.5
         refraction 1.33}
}
