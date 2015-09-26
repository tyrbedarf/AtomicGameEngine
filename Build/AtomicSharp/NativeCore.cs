﻿using System;
using System.Collections.Generic;

namespace AtomicEngine
{
	static class NativeCore
	{
		// given an existing instance classID, construct the managed instance, with downcast support (ask for Component, get StaticModel for example)
		public static Dictionary<IntPtr, Func<IntPtr, RefCounted>> nativeClassIDToManagedConstructor = new Dictionary<IntPtr, Func<IntPtr, RefCounted>>();

		public static Dictionary<IntPtr, WeakReference> nativeLookup = new Dictionary<IntPtr, WeakReference> ();

		public static IntPtr RegisterNative (IntPtr native, RefCounted r)
		{
			var w = new WeakReference (r);
			NativeCore.nativeLookup [native] = w;
			RefCounted._AddRef (native);
			return native;
		}

		public static void ReleaseExpiredNativeReferences()
		{
			List<IntPtr> released = new List<IntPtr> ();

			foreach(KeyValuePair<IntPtr, WeakReference> entry in nativeLookup)
			{

				if (entry.Value.Target == null || !entry.Value.IsAlive) {										
					released.Add (entry.Key);

				} else {

				}

			}

			foreach (IntPtr native in released) {
				RefCounted._ReleaseRef(native);
				nativeLookup.Remove (native);
			}

		}

		// wraps an existing native instance, with downcast support
		public static T WrapNative<T> (IntPtr native) where T:RefCounted
		{
			if (native == IntPtr.Zero)
				return null;

			WeakReference w;

			// first see if we're already available
			if (nativeLookup.TryGetValue (native, out w)) {

				if (w.IsAlive) {

					// we're alive!
					return (T)w.Target; 

				} else {

					// we were seen before, but have since been GC'd, remove!
					nativeLookup.Remove (native);
				}
			}

			IntPtr classID = RefCounted.csb_RefCounted_GetClassID (native);

			// and store, with downcast support for instance Component -> StaticModel
			w = new WeakReference (nativeClassIDToManagedConstructor[classID](native));
			NativeCore.nativeLookup [native] = w;

			// store a ref, so native side will not be released while we still have a reference in managed code
			RefCounted._AddRef (native);

			return (T) w.Target;

		}
	}

}

