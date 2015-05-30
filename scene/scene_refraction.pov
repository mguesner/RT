camera
{
	location <0,0,0> // la position de l'observateur
	look_at <1000,0,0>  // le point de vue
}

light_source { <1000,0,0>
		color rgb<1,1,1>
}

sphere { <2000,0,0>, 500 // coord centre et rayon
         pigment { color rgb <1,1,1> }
         finish {transparence 0.5
         refraction 2.0}
}

cylinder_42 { <4000,0,0>, <0,1,0>, 100 // coord, direction, rayon
         pigment { color rgb <0,1,0> }
}

plane { <-1,0,0>,6000 // coord centre et rayon
         pigment { color rgb <1,1,1> }
}

