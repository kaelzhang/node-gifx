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

.background('#ffffff')  // Sets the background color to '#ffffff',
                        // default to transparent)

.unit(500)              // Sets the unit time to 500 ms,
                        // i.e. each frame will last 500 ms
.layer()                      
  .start(0)             // Starts from the first frame.
                        // The index of a frame begins with 0.

  .duration(2)          // The duration is 1 second

  .add(catBuffer)       // Adds a cat

  .leave()              // Returns to the stage
.layer()
  .start(2)             // Starts from the dog frame

  .end(4)               // Ends at (and INCLUDES) the frame of index 4 (the     
                        // fifth frame)
                        // which has the same effect with `.duration(3)`

  .add(dogBuffer, {     // Adds a dog with a x-axis offset of 150
    x: 150,
    y: 0
  })
  .leave()
.repeat(0)              // Repeat infinitely

.stream()               // Creates a readable stream and write to file.
.pipe(fs.createWriteStream('cat-and-dog.gif'))
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
