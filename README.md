# Gifx

CURRENTLY STILL WORKING IN PROGRESS, DO NOT USE.

The GIF maker, reader and mangler, which is a native node.js bindings to the giflib.

## install

```sh
$ npm i gifx
```

## Usage

```js
import Gifx from 'gifx'

const catBuffer = fs.readFileSync(filepathCat)
const dogBuffer = fs.readFileSync(filepathDog)

// Creates a new 300x200(square pixels) stage
new Gifx(300, 200)
// Sets the background color to '#ffffff' (default to transparent)
.background('#ffffff')
// Sets the unit time to 500 ms, i.e. each frame will last 500 ms
.unit(500)
.layer()
  // Starts from the first frame.
  // The index of a frame begins with 0.
  .start(0)
  // The duration is 1 second
  .duration(2)
  // Adds a cat
  .add(catBuffer)
  // Returns to the stage
  .leave()

// You could babel the layer with a name
.layer()
  // Starts from the dog frame
  .start(2)
  // Ends at (and INCLUDES) the frame of index 4 (the fifth frame)
  // which has the same effect with `.duration(3)`
  .end(4)
  // Adds a dog with a x-axis offset of 150
  .add(dogBuffer, {
    x: 150,
    y: 0
  })
  .leave()

// Repeat infinitely
.repeat(0)
// Creates a readable stream and write to file.
.stream().pipe(fs.createWriteStream('cat-and-dog.gif'))
```

# new Gifx(width, height)

## gif.unit(milliseconds = 1)

- **milliseconds** `number=1`

Returns `this`

## gif.layer()

Returns `Layer`

## gif.repeat(repeat)

- **repeat** `number | boolean`
  - `0 | true`: infinite loop
  - `1 | false`: no repeat
  - other number, `3` for example: plays 3 times

Returns `gif`

## gif.stream()

Returns `Stream.Readable`

# Layer

## layer.start(start)

- **start** `number` the

## layer.duration(duration)

## layer.end(end)

## layer.leave()

Returns `Gifx`
