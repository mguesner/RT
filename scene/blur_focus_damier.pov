camera
{
   location <0,0,0> // la position de l'observateur
   look_at <1000,0,0>  // le point de vue
   //right x*image_width/image_height  // aspect ratio
   //angle 45 // l'angle de la caméra
}

light_source { <0,0,-1000>
      color rgb<1,1,1>
}

sphere { <1000,-500,0>, 200 // coord centre et rayon
         pigment { color rgb <0.5,0,0.5> }
         texture { name gravas2 }
}

sphere { <2000,-250,0>, 200 // coord centre et rayon
         pigment { color rgb <0.5,0,0.5> }
         texture { name gravas2 }
}

sphere { <3000,125,0>, 200 // coord centre et rayon
         pigment { color rgb <0.5,0,0.5> }
         texture { name gravas2 }
}

sphere { <4000,500,0>, 200 // coord centre et rayon
         pigment { color rgb <0.5,0,0.5> }
         texture { name gravas2 }
}

sphere { <5000,1000,0>, 200 // coord centre et rayon
         pigment { color rgb <0.5,0,0.5> }
         texture { name gravas2 }
}

plane { <-1,0,0>,6000 // plane devant
         pigment { color rgb <1,1,1> }
         damier { color rgb <0.8,1,0.8> long 20 }
}