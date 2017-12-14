import bindings from '../build/Release/gifx'
import path from 'path'

const {Gifx} = bindings

export default Gifx

const PATH_GIF_LIB = path.join(__dirname, '..', 'gitlib')
export {
  PATH_GIF_LIB
}
