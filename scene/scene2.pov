camera
{
   location <0,0,0> // la position de l'observateur
   look_at <1000,0,0>  // le point de vue
   //right x*image_width/image_height  // aspect ratio
   //angle 45 // l'angle de la caméra
}

light_source { <1500,1000,0>
      color rgb<1,1,1>
}

light_source { <1500,-1000,0>
      color rgb<1,1,1>
}

//light_source { <-2000,600,1000>
//     color rgb<1,1,1>
//}

//sphere { <2030,10,400>, 200 // coord centre et rayon
//         pigment { color rgb <1,0,0> }
//}


sphere { <3000,0,0>, 100 // coord centre et rayon
         pigment { color rgb <0,1,0> }
}

//plane { <1,0,0>,2000 // coord centre et rayon
//         pigment { color rgb <0.5,0.5,0> }
//}
