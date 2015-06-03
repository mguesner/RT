camera
{
   location <-0,-100,0> // la position de l'observateur
   look_at <0,0,1000>  // le point de vue
   //right x*image_width/image_height  // aspect ratio
   //angle 45 // l'angle de la caméra
}

light_source { <0,0,1000>
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
         texture { jupitermap }
}

sphere { <0,500,1300>, 200 // coord centre et rayon
         pigment { color rgb <1,1,1> }
         finish {transparence 0.95
         refraction 2.0}
}

cylinder_42{ <-250,-250,1500>, <1,0,0>, 100 // coord centre et rayon
         pigment { color rgb <1,0,0> }
         finish {specular 1}
}

plane { <1,0,0>,1000 // coord centre et rayon
        // pigment { color rgb <0,1,0> }
        texture { damier2 }
}

plane { <0,0,-1>,10000 // coord centre et rayon
         pigment { color rgb <1,1,1> }
         texture { damier2 }
         //finish {reflection 1.0}
}
