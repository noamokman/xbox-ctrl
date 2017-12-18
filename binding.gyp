{
  "targets": [
    {
      "target_name": "xboxCtrl",
      "sources": [
        "src/index.cc",
        "src/helper.cc",
        "src/Off/Off.cc",
        "src/Off/offActions.cc",
        "src/List/List.cc",
        "src/List/listActions.cc",
        "src/Vibrate/Vibrate.cc",
        "src/Vibrate/vibrateActions.cc"
      ],
      "include_dirs": [
        "src",
        "<!(node -e \"require('nan')\")"
      ]
    }
  ]
}
