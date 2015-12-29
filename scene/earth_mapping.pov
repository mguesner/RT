camera
{
   location <0,0,0> // la position de l'observateur
   look_at <0,1000,0>  // le point de vue
   //right x*image_width/image_height  // aspect ratio
   //angle 45 // l'angle de la caméra
}

light_source { <0,0,-2500>
      color rgb<1,1,1>
}

sphere { <550,1500,0>, 500 // coord centre et rayon
         pigment { color rgb <0.5,0,0.5> }
         texture { name earth
         norme bump_earth
        }
}

sphere { <-550,1500,0>, 500 // coord centre et rayon
         pigment { color rgb <0.5,0,0.5> }
         texture { name earth
        }
}