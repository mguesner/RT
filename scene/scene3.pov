camera
{
	location <0,0,0> // la position de l'observateur
	look_at <1,0,0>  // le point de vue
	//right x*image_width/image_height	// aspect ratio
	//angle 45 // l'angle de la caméra
}

light_source { <2000,500,500>
      color rgb<1,1,1>
}

//light_source { <-2000,600,1000>
//     color rgb<1,1,1>
//}

//sphere { <2030,10,400>, 200 // coord centre et rayon
//         pigment { color rgb <1,0,0> }
//}


sphere { <2030,750,400>, 100 // coord centre et rayon
         pigment { color rgb <0,1,0> }
}

plane { <0,0,1>,0 // coord centre et rayon
         pigment { color rgb <0.5,0,0> }
}

plane { <-1,0,0>,6000 // coord centre et rayon
         pigment { color rgb <0.5,0.5,0> }
}


cylinder_42 { <4500,0,1000>, <0,1,0>, 200 // coord, direction, rayon
         pigment { color rgb <1,0.6,0> }
}

cone_42 { <5000, -1000, 500>, 1, <0,1,0>   // coord, angle, direction
     pigment { color rgb <0.4,0.7,0> }
}

