unsigned int reverse_nibbles(unsigned int x)
{
  unsigned int out = 0, i;
  for(i = 0; i < 4; ++i)
  {
    const unsigned int byte = (x >> 8 * i) & 0xff;
    out |= byte << (24 - 8 * i);
  }
  return out;
}
