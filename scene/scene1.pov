camera
{
	location <0,0,0> // la position de l'observateur
	look_at <1000,0,0>  // le point de vue
}

light_source { <2500,1500,0>
		color rgb<1,1,1>
}

//sphere { <2000,0,0>, 200 // coord centre et rayon
//         pigment { color rgb <1,0.6,0> }
//}

cylinder_42 { <2500,0,0>, <0,1,0>, 100 // coord, direction, rayon
         pigment { color rgb <1,0.6,0> }
}
