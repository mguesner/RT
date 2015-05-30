camera
{
	location <0,200,200> // la position de l'observateur
	look_at <1000,100,100>  // le point de vue
}

light_source { <100,-200,0>
		color rgb<1,1,1>
}

plane { <-1,0,0>,3000 // coord centre et rayon
         pigment { color rgb <1,0,0> }
}
