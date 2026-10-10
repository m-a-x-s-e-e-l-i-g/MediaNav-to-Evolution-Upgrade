// Constructor variant arguments do not necessarily describe extra sprite banks.
// Require the bitmap to hold full native-width frames before selecting a bank.
export function spriteSlice(imageWidth, drawWidth, states, variants, state, alternate) {
  const banks = states === 4 && imageWidth === drawWidth * states * variants ? variants : 1;
  const bank = alternate && banks > 1 ? 1 : 0;
  const frameWidth = states === 4 ? imageWidth / (states * banks) : drawWidth;
  return { banks, frameWidth, sourceX: (bank * states + (states === 4 ? state : 0)) * frameWidth };
}
