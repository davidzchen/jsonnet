package com.google.jsonnet;

class JsonnetVm {
  /**
   * Set the max stack depth.
   */
  public native void setMaxStack(int v);

  /**
   * Set the number of objects required before a garbage collection cycle is
   * allowed.
   */
  public native void setGcMinObjects(int v);

  /**
   * Run the garbage collector after this amount of growth in the number of
   * objects.
   */
  public native void setGcGrowthTrigger(double v);

  /**
   * Expect a string as output and don't JSON encode it.
   */
  public native void expectStringOutput(boolean v);
}
