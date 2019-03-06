package jp.co.geniee.sdk.ads.nativead;

import android.app.Activity;

import java.util.HashMap;

public class GNNativeAdActivityBridge {

    private static Activity mActivity;
    private static GNNativeAdRequest mNativeAdRequest;
    private static HashMap<String, GNNativeAd> mNativeAds = new HashMap<String, GNNativeAd>();

    // cocos2dxへのcallback
    public static native void onNativeAdsLoaded(GNNativeAd[] nativeAds);

    public static native void onNativeAdsFailedToLoad();

    public static native boolean onShouldStartInternalBrowserWithClick(String url);

    private static class CCGNNativeAdRequestDelegate implements GNNativeAdRequestListener {

        public CCGNNativeAdRequestDelegate() {
        }

        @Override
        public void onNativeAdsLoaded(GNNativeAd[] nativeAds) {
            for (GNNativeAd nativeAd : nativeAds) {
                mNativeAds.put(nativeAd.zoneID, nativeAd);
            }
            GNNativeAdActivityBridge.onNativeAdsLoaded(nativeAds);
        }

        @Override
        public void onNativeAdsFailedToLoad() {
            GNNativeAdActivityBridge.onNativeAdsFailedToLoad();
        }

        @Override
        public boolean onShouldStartInternalBrowserWithClick(String url) {
            return GNNativeAdActivityBridge.onShouldStartInternalBrowserWithClick(url);
        }
    }

    public GNNativeAdActivityBridge(Activity activity) {
        mActivity = activity;
    }

    public static void initialize(final String zoneId) {
        mActivity.runOnUiThread(new Runnable() {
            @Override
            public void run() {

                try {

                    mNativeAdRequest = new GNNativeAdRequest(mActivity, zoneId);
                    mNativeAdRequest.setAdListener(new CCGNNativeAdRequestDelegate());
                } catch (IllegalArgumentException e) {
                    GNNativeAdActivityBridge.onNativeAdsFailedToLoad();
                }
            }
        });
    }

    public static void loadAds() {
        mActivity.runOnUiThread(new Runnable() {
            @Override
            public void run() {
                if (mNativeAdRequest != null) {
                    mNativeAdRequest.loadAds(mActivity);
                }
            }
        });
    }

    public static void multiLoadAds() {
        mActivity.runOnUiThread(new Runnable() {
            @Override
            public void run() {
                if (mNativeAdRequest != null) {
                    mNativeAdRequest.multiLoadAds(mActivity);
                }
            }
        });
    }

    public static void onTrackingImpression(final String zoneId) {
        mActivity.runOnUiThread(new Runnable() {
            @Override
            public void run() {
                GNNativeAd nativeAd = mNativeAds.get(zoneId);
                if (nativeAd != null) {
                    nativeAd.onTrackingImpression();
                }
            }
        });
    }

    public static void onTrackingClick(final String zoneId) {
        mActivity.runOnUiThread(new Runnable() {
            @Override
            public void run() {
                GNNativeAd nativeAd = mNativeAds.get(zoneId);
                if (nativeAd != null) {
                    nativeAd.onTrackingClick();
                }
            }
        });
    }

    public void onStart() {
    }

    public void onResume() {
    }

    public void onPause() {
    }

    public void onStop() {
    }

    public void onDestroy() {
    }

}
