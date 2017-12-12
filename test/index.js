import test from 'ava'
import Gifx from '../src'

test('constructor', async t => {
  const gif = new Gifx()
  t.is(gif, gif.hello())
})
