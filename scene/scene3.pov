camera
{
	location <0,0,0> // la position de l'observateur
	look_at <1,0,0>  // le point de vue
}

light_source { <0,0,0>
      color rgb<1,1,1>
}


//light_source { <-2000,600,1000>
//     color rgb<1,1,1>
//}

//sphere { <5000,0,0>, 300 // coord centre et rayon
//         pigment { color rgb <1,0,1> }
//}


//sphere { <100,0,0>, 5 // coord centre et rayon
//         pigment { color rgb <0,1,0> }
//}

//plane { <0,0,1>,-10 // coord centre et rayon
//         pigment { color rgb <0.5,0,0> }
//}

//plane { <-1,0,0>,6000 // coord centre et rayon
//         pigment { color rgb <1,0,0> }
//}

//cylinder_42 { <5000,1000,100>, <0,1,1>, 100 // coord, direction, rayon
//         pigment { color rgb <1,0.6,0> }
//}

cone_42 { <100, 0, 0>, 0.5, <0,0,1>   // coord, angle, direction
     pigment { color rgb <0.4,0.7,0> }
}
