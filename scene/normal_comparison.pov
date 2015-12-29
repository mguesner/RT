camera
{
   location <0,0,0> // la position de l'observateur
   look_at <1000,0,0>  // le point de vue
   //right x*image_width/image_height  // aspect ratio
   //angle 45 // l'angle de la caméra
   ambient_light 0.10 //lumiere ambiant
}

light_source { <0,-1500,0>
      color rgb<1,1,1>
}



sphere { <5000,-1500,0>, 1000 // coord centre et rayon
        texture { name semiblanc
        norme bump_dalles
         //etir <0.2,0.2,0> 
         }
}

sphere { <5000,1500,0>, 1000 // coord centre et rayon
        texture { name semiblanc
        norme bump_dalles
         //etir <0.2,0.2,0> 
         }
}
