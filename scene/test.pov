camera
{
	location <0,1,-3> // la position de l'observateur
	look_at <0,1,0>  // le point de vue
	//right x*image_width/image_height	// aspect ratio
	//angle 45 // l'angle de la caméra
}

light_source { <300, 1500,-2500>
		color rgb<1,1,1>
}

plane { <0,1,0>, 0
         pigment { color rgb <1,0.6,0> }
}

sphere { <0,1,0>, 0.5 // coord centre et rayon
         pigment { color rgb <1,0.6,0> }
}

//cylinder { <0,0,0>, <0,1,0>, 0.25 // coord chaque bout et rayon
//         pigment { color rgb <1,0.6,0> }
//}

cylinder_42 { <3,2,1>, <0,1,0>, 0.2 // coord, direction, rayon
         pigment { color rgb <1,0.6,0> }
}

//cone { <0,0,0>, 1, <0,1.75,0>, 0.5 // coord et rayon de chaque bout
//      pigment { color rgb <0.4,0.7,0> }
//}

cone_42 { <0,0,0>, 1, <0,1.75,0>   // coord, angle, direction
      pigment { color rgb <0.4,0.7,0> }
}
