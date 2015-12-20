camera
{
   location <0,0,0> // la position de l'observateur
   look_at <1000,0,0>  // le point de vue
   //right x*image_width/image_height  // aspect ratio
   //angle 45 // l'angle de la caméra
}

light_source { <1500,600,500>
      color rgb<1,1,1>
}

sphere { <3000,-1000,0>, 600 // coord centre et rayon
         pigment { color rgb <0,1,0> }
}

sphere { <6000,1000,0>, 600 // coord centre et rayon
         pigment { color rgb <0,1,0> }
}

sphere { <9000,3000,0>, 600 // coord centre et rayon
         pigment { color rgb <0,1,0> }
}

sphere { <12000,5000,0>, 600 // coord centre et rayon
         pigment { color rgb <0,1,0> }
}

sphere { <15000,7000,0>, 600 // coord centre et rayon
         pigment { color rgb <0,1,0> }
}

sphere { <18000,9000,0>, 600 // coord centre et rayon
         pigment { color rgb <0,1,0> }
}