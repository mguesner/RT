camera
{
	location <0,0,0> // la position de l'observateur
	look_at <1000,0,0>  // le point de vue
}

light_source { <0,0,0>
		color rgb<1,1,1>
}

//cylinder_42 { <2500,0,0>, <0,1,1>, 100 // coord, direction, rayon
//         pigment { color rgb <1,0.6,0> }
//}

//plane { <-1,0,0>,6000 // coord centre et rayon
//         pigment { color rgb <1,0,0> }
//}

triangle { <100,0,0>, <500, 100, 100>, <1, 50, 500> // coord, u, v
		 pigment { color rgb <1,1,0> }
}

//sphere { <500,0,0>, 200 // coord centre et rayon
//        pigment { color rgb <1,0.6,0> }
//}

//triangle { <0,1,0>, <1000, 150, 300>, <0, -20, 40> // coord, u, v
//		 pigment { color rgb <0,0,1> }
//}

//c'est faux c'est de la merde.