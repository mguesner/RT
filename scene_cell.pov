camera
{
	location <0,0,0> // la position de l'observateur
	look_at <1000,0,0>  // le point de vue
}

light_source { <2000,2000,-2000>
		color rgb<1,1,1>
}

light_source { <2000,-2000,-2000>
      color rgb<1,1,1>
}

cylinder_42 { <6000,-1500,1000>, <0,0.5,0.5>, 500 // coord, direction, rayon
         pigment { color rgb <1,0,1> }
         finish {specular 1}
}

cylinder_42 { <6000,1500,1000>, <0,0.5,0.5>, 500 // coord, direction, rayon
         pigment { color rgb <1,0,1> }
         finish {specular 1}
}

plane { <-1,0,0>,6000 // coord centre et rayon
         pigment { color rgb <0,0,1> }
}

plane { <0,0,-1>,1000 // coord centre et rayon
         pigment { color rgb <1,0,0> }
}

sphere { <6000,-2000,330>, 800 // coord centre et rayon
         pigment { color rgb <1,0,0> }
         finish {specular 1}
}

sphere { <6000,-1400,-600>, 800 // coord centre et rayon
         pigment { color rgb <1,0,0> }
         finish {specular 1}
}

sphere { <6000,-1500,-1530>, 800 // coord centre et rayon
         pigment { color rgb <1,0,0> }
         finish {specular 1}
}

sphere { <6000,3500,330>, 1000 // coord centre et rayon
         pigment { color rgb <0,1,0> }
         finish {specular 1}
}

cone_42 { <6000,1500,0>, 0.2, <0,0.5,-0.5>   // coord, angle, direction
     pigment { color rgb <0.4,0.7,0> }
}