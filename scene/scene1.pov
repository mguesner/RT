camera
{
	location <0,0,1> // la position de l'observateur
	look_at <1,0,1>  // le point de vue
	right x*image_width/image_height	// aspect ratio
	angle 45 // l'angle de la caméra
}

light_source { <-2,2,3>
		color rgb<1,1,1>*0.8
}

light_source { <-2,-2,2>
      color rgb<1,1,1>*0.8
}

sphere { <2,1,0>, 0.5 // coord centre et rayon
         pigment { color rgb <1,0.6,0> }
}

sphere { <2,-1,0>, 0.5 // coord centre et rayon
         pigment { color rgb <1,0.6,0> }
}

plane { <5,5,0>, 0
         pigment { color rgb <1,0.6,0> }
}

plane { <0,5,5>, 5
         pigment { color rgb <1,0.6,0> }
}

cylinder_42 { <3,1,-2>, <3,-3,5>, 0.5 // coord chaque bout et rayon
         pigment { color rgb <1,0.6,0> }
}

cone_42 { <3,4,4>, 1, <3,-6,-6>, 2 // coord et rayon de chaque bout
      pigment { color rgb <0.4,0.7,0> }
}
