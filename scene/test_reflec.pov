camera
{
   location <0,0,0> // la position de l'observateur
   look_at <1000,0,0>  // le point de vue
}

light_source { <1000,1500,0>
      color rgb<1,1,1>
}

cylinder_42 { <2000,0,1000>, <0,0,1>, 50 // coord, direction, rayon
         pigment { color rgb <0,1,0> }
         finish {specular 1}
}

plane { <-1,0,0>,3000 // coord centre et rayon
         pigment { color rgb <1,1,1> }
         finish {reflection 1}
}
