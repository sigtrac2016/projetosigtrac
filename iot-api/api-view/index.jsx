import React from 'react';
import _ from 'lodash';
import $ from 'jquery';
import {render} from 'react-dom';
import Griddle from 'griddle-react';

import apiRoutes from './api-routes';

// The Grid component
class Grid extends React.Component {
  constructor() {
    super();
    this.state = {
      source: "default",
      apiData: [],
    };
    this.baseUrl = "http://localhost:8080/api/";

    this. _handleChange = this. _handleChange.bind(this);
  }

  _handleChange(e) {
    this.setState({
      source: e.target.value
    });
    this.serverRequest = $.get(this.baseUrl + e.target.value);
    this.serverRequest.done(function (result) {
        this.setState({
          apiData: result
        });
      }.bind(this));
    this.serverRequest.fail(function () {
        this.setState({
          apiData: []
        });
      }.bind(this));
  }

  render () {
    var options = _.map(apiRoutes, (apiOption) => {
      return (
        <option value={apiOption} key={_.uniqueId("apioption_")}>{apiOption}</option>
      );
    });

    return <div>
      <select onChange={this._handleChange} value={this.state.source}>
        <option value="default" disabled>Api route (/api/)</option>
        {options}
      </select>
      <Griddle className="griddle"
        results={this.state.apiData} showFilter={true} resultsPerPage={5}
        enableInfiniteScroll={true} bodyHeight={400}/>
    </div>;
  }
}

render(<Grid />, document.getElementById('app'));
