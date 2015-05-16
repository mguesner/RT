camera
{
   location <0,0,0> // la position de l'observateur
   look_at <0,0,1000>  // le point de vue
   //right x*image_width/image_height  // aspect ratio
   //angle 45 // l'angle de la caméra
}

light_source { <0,0,1500>
      color rgb<1,1,1>
}

//light_source { <-2000,600,1000>
//     color rgb<1,1,1>
//}

//sphere { <2030,10,400>, 200 // coord centre et rayon
//         pigment { color rgb <1,0,0> }
//}


sphere { <250,250,1500>, 100 // coord centre et rayon
         pigment { color rgb <0,1,0> }
}

plane { <0,1,0>,100 // coord centre et rayon
         pigment { color rgb <0.5,0,0> }
}

plane { <0,0,-1>,2000 // coord centre et rayon
         pigment { color rgb <0.5,0.5,0> }
}

//cylinder_42 { <1800,0,1000>, <0,1,0>, 200 // coord, direction, rayon
//         pigment { color rgb <1,0.6,0> }
//}

//cone_42 { <-250, 250, 1500>, 1, <0,1,0>   // coord, angle, direction
//    pigment { color rgb <0.4,0.7,0> }
//}
