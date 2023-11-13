In an attempt to learn C++ I created a program to simulate orbits of celestial bodies.

## Input

The program reads in a json file with the attributes of N bodies in the form of:

```json
{
  "bodies": [
    {
      "mass": 10000,
      "radius": 10,
      "pos_x": 600,
      "pos_y": 400,
      "vel_x": 0.5,
      "vel_y": 1.5,
      "drawline": true
    },
    {
      "mass": 10000,
      "radius": 10,
      "pos_x": 1000,
      "pos_y": 450,
      "vel_x": -0.5,
      "vel_y": -1.5,
      "drawline": true
    }
  ],
  "stay_in_bounds": true
}
```
Above is an example taken from ```stable_orbit.json``` 

<ul>
  <li>**mass**: mass of body n (int)</li>
  <li>**radius**: radius of body n (int) </li>
  <li>**pos_x**: inital x position of body n (int) </li>
  <li>**pos_y**: inital y position of body n (int)</li>
  <li>**vel_x**: inital x velocity of body n (int) </li>
  <li>**vel_y**: inital y velocity of body n (int) </li>
  <li>**drawline**: determines if the program will draw a trailing line of the body n's previous movement (bool)</li>
  <l1>**stay_in_bounds**: determines wether all the bodies will stay in the screen bounds by boncing off the edges (bool)</li>
</ul>



