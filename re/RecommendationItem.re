open ReactNative;

module Style = {
  open ReactNative.Style;
  let content =
    style [
      flex 1.,
      paddingTop 15.,
      paddingHorizontal 25.,
      backgroundColor Colors.white,
      marginBottom 25.
    ];
  let container =
    style [
      height 325.,
      shadowOpacity 0.3,
      shadowRadius 3.,
      shadowOffset height::3. width::0.,
      marginBottom 10.,
      borderTopWidth 1.,
      borderTopColor Colors.alabaster
    ];
  let image = style [height 200., width (float_of_int Theme.width)];
  let title =
    style [alignItems `flexStart, justifyContent `center, fontSize 26., fontWeight `_600];
  let description = style [height 65., fontSize 14.];
};

let component = ReasonReact.statelessComponent "RecommendationItem";

let make ::title ::description _children => {
  ...component,
  render: fun _self =>
    <View style=Style.container>
      <Image
        source=Image.(Required (Packager.require "../../../assets/images/montserrat.png"))
        resizeMode=`cover
        style=Style.image
      />
      <View style=Style.content>
        <CustomText style=Style.title> title </CustomText>
        <CustomText style=Style.description> description </CustomText>
      </View>
    </View>
};
