camera
{
   location <0,0,0> // la position de l'observateur
   look_at <1000,0,0>  // le point de vue
   //right x*image_width/image_height  // aspect ratio
   //angle 45 // l'angle de la caméra
}

light_source { <0,0,0>
		color rgb<1,1,1>
}

plane { <-1,0,0>,4500 // coord centre et rayon
         pigment { color rgb <1,1,1> }
         finish {reflection 1}
}

sphere { <-1000,-1000,-1000>, 500 // coord centre et rayon
         pigment { color rgb <0,0,1> }
         finish {specular 1}
}

plane { <1,0,0>,4500 // coord centre et rayon
         pigment { color rgb <1,1,1> }
         finish {reflection 1}
}

plane { <0,1,0>,4500 // coord centre et rayon
         pigment { color rgb <1,1,1> }
         finish {reflection 1}
}

plane { <0,-1,0>,4500 // coord centre et rayon
         pigment { color rgb <1,1,1> }
         finish {reflection 1}
}

plane { <0,0,-1>,4500 // coord centre et rayon
         pigment { color rgb <1,1,1> }
         finish {reflection 1}
}

plane { <0,0,1>,4500 // coord centre et rayon
         pigment { color rgb <1,1,1> }
         finish {reflection 1}
}



