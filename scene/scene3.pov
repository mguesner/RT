camera
{
	location <10,10,510> // la position de l'observateur
	look_at <510,10,510>  // le point de vue
	//right x*image_width/image_height	// aspect ratio
	//angle 45 // l'angle de la caméra
}

light_source { <3000,2010,500>
      color rgb<1,1,1>
}

//light_source { <-2000,600,1000>
//     color rgb<1,1,1>
//}

//sphere { <2030,10,400>, 200 // coord centre et rayon
//         pigment { color rgb <1,0,0> }
//}

//sphere { <2030,-250,400>, 100 // coord centre et rayon
//         pigment { color rgb <0,1,0> }
//}

plane { <0,0,1>,0 // coord centre et rayon
         pigment { color rgb <0.5,0,0> }
}

//cylinder_42 { <3000,1000,1000>, <0,1,0>, 200 // coord, direction, rayon
//         pigment { color rgb <1,0.6,0> }
//}

cone_42 { <5000, 10, 500>, 1, <0,1,0>   // coord, angle, direction
     pigment { color rgb <0.4,0.7,0> }
}