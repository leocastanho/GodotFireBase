package org.godotengine.godot;

import android.app.Activity;
import android.content.Context;

import com.crashlytics.android.Crashlytics;

import com.google.firebase.FirebaseApp;

public class Crash {

    public static Crash getInstance (Activity p_activity) {
		if (mInstance == null) {
			synchronized (Crash.class) {
				mInstance = new Crash(p_activity);
			}
		}

		return mInstance;
	}

	public Crash(Activity p_activity) {
		activity = p_activity;
	}

    private static Context context;
	private static Activity activity;

	private FirebaseApp mFirebaseApp = null;

	private static Crash mInstance = null;
}
