camera
{
   location <0,0,0> // la position de l'observateur
   look_at <0,0,1000>  // le point de vue
   //right x*image_width/image_height  // aspect ratio
   //angle 45 // l'angle de la caméra
}

light_source { <0,0,-1000>
      color rgb<1,1,1>
}

sphere { <250,250,1500>, 100 // coord centre et rayon
         pigment { color rgb <0.5,0,0.5> }
         texture { name gravas2 }
}

sphere { <0,500,1300>, 200 // coord centre et rayon
         pigment { color rgb <1,1,1> }
          finish {
            transparence 1.0
            refraction 1.0
          }
}

cylinder_42{ <-250,-250,1500>, <1,0,0>, 100 // coord centre et rayon
         pigment { color rgb <1,0,0> }
         finish {specular 1}
         texture { name gravas }
}

cone_42 { <0,300,2500>, 0.2, <1,0,0>   // coord, angle, direction
     texture { name damier }
     pigment { color rgb <0.4,0.7,0> }
}

plane { <1,0,0>,1000 // plane mur sol
        // pigment { color rgb <0,1,0> }
        texture { name damier2 }
}

plane { <-1,0,0>,1000 // plane mur plafond
        // pigment { color rgb <0,1,0> }
        texture { name damier2 }
}


plane { <0,0,1>,10000 // plane derriere
         pigment { color rgb <1,1,1> }
         texture { name damier2 }
         //finish {reflection 1.0}
}

plane { <0,1,0>,1000 // plane mur gauche
        // pigment { color rgb <0,1,0> }
        texture { name damier2 }
}

plane { <0,-1,0>,1000 // plane mur droit
        // pigment { color rgb <0,1,0> }
        texture { name damier2 }
}
