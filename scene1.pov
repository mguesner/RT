camera
{
   location <-0,-100,0> // la position de l'observateur
   look_at <0,0,1000>  // le point de vue
   ambient_light 0.2 //lumiere ambiant
   //right x*image_width/image_height  // aspect ratio
   //angle 45 // l'angle de la caméra
}

light_source { <0,0,1000>
      color rgb <1,1,1>
}

sphere { <250,250,1500>, 100 // coord centre et rayon
         pigment { color rgb <0,1,0> }
         texture { name jupiter }
}

sphere { <0,500,1300>, 200 // coord centre et rayon
         pigment { color rgb <1,1,1> }
         finish {transparence 0.95
         refraction 2.0}
}

cylinder_42{ <-250,-250,1500>, <1,0,0>, 100 // coord centre et rayon
         pigment { color rgb <1,0,0> }
         finish {specular 1}
         perlin 10
}

plane { <1,0,0>,1000 // coord centre et rayon
         pigment { color rgb <1,1,0.6> }
         perlin 1000
        //texture { name brickwork
         //norme brickworkmap
         //etir <0.2,0.2,0> 
         //}
}

plane { <0,0,-1>,10000 // coord centre et rayon
         pigment { color rgb <1,1,1> }
         texture { name gravas
         etir <0.1,0.1,0>}
         //finish {reflection 1.0}
}
