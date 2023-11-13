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
  <li> <strong> mass </strong>: mass of body n (int) </li>
  <li> <strong> radius </strong>: radius of body n (int) </li>
  <li> <strong> pos_x </strong>: inital x position of body n (int) </li>
  <li> <strong> pos_y </strong>: inital y position of body n (int)</li>
  <li> <strong> vel_x </strong>: inital x velocity of body n (int) </li>
  <li> <strong> vel_y </strong>: inital y velocity of body n (int) </li>
  <li> <strong> drawline </strong>: determines if the program will draw a trailing line of the body n's previous movement (bool) </li>
  <li> <strong> stay_in_bounds </strong>: determines wether all the bodies will stay in the screen bounds by boncing off the edges (bool)</li>
</ul>

## Examples
https://github.com/JakeTaranov/oribtsim/assets/48743548/c234fd49-8c1c-4492-ad4f-a78886aa6275



https://github.com/JakeTaranov/oribtsim/assets/48743548/db372364-ecda-41f2-9018-2b14eed51053





