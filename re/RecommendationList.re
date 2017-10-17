open ReactNative;

module Style = {
  open ReactNative.Style;
  let container = style [flex 1., backgroundColor Colors.alabaster];
};

let component = ReasonReact.statelessComponent "RecommendationList";

let make _children => {
  ...component,
  render: fun _self =>
    <ScrollView style=Style.container>
      <NavBar />
      <RecommendationItem
        title="Montserrat"
        description="The holy church on top of the mountain is a wonderful place of worship and climbing. There are also cool via ferratas to visit..."
      />
      <RecommendationItem
        title="Montserrat"
        description="The holy church on top of the mountain is a wonderful place of worship and climbing. There are also cool via ferratas to visit and the MOntserrat Mujahedins that will keep you on your toes all the time. Heartily recommend!"
      />
      <RecommendationItem
        title="Montserrat"
        description="The holy church on top of the mountain is a wonderful place of worship and climbing. There are also cool via ferratas to visit and the MOntserrat Mujahedins that will keep you on your toes all the time. Heartily recommend!"
      />
    </ScrollView>
};
