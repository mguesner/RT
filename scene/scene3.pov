camera
{
	location <0,0,0> // la position de l'observateur
	look_at <1000,0,0>  // le point de vue
	//right x*image_width/image_height	// aspect ratio
	//angle 45 // l'angle de la caméra
}

light_source { <-1000,0,0>
      color rgb<1,1,1>
}

//light_source { <-2000,600,1000>
//     color rgb<1,1,1>
//}

sphere { <2000,-100,-100>, 500 // coord centre et rayon
         pigment { color rgb <1,0,0> }
}


//sphere { <2030,750,400>, 100 // coord centre et rayon
//         pigment { color rgb <0,1,0> }
//}

//plane { <0,0,1>,-10 // coord centre et rayon
//         pigment { color rgb <0.5,0,0> }
//}

plane { <-1,0,0>,6000 // coord centre et rayon
         pigment { color rgb <0.5,0.5,0> }
}

cylinder_42 { <1500,0,0>, <0,1,0>, 100 // coord, direction, rayon
         pigment { color rgb <1,0.6,0> }
}

//cone_42 { <5000, 0, 0>, 1, <0,1,0>   // coord, angle, direction
//     pigment { color rgb <0.4,0.7,0> }
//}
