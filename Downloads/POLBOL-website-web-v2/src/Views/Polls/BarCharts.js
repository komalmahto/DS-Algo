import React, { useState, useEffect } from "react";
import Chart from "react-apexcharts";
import Dropdown from "react-bootstrap/Dropdown";
import { FiCheck } from "react-icons/fi";
import { FiXCircle } from "react-icons/fi";
import { ToastContainer, toast } from "react-toastify";
import "react-toastify/dist/ReactToastify.css";
import "./graph.css";
import DropdownCascade from "react-dropdown-cascade";

function BarCharts(props) {
  const [data, setData] = useState(null);
  const [dropdownValue, setDropdownValue] = useState("Select filter");
  const [it,setIt]=useState([])

  const [filters, setFilters] = useState({
    nofilters: {},
    gender: {},
    age: {},
    region: {},
  });

  const [filtersVotes, setFiltersVotes] = useState({
    nofilters: {},
    gender: {},
    age: {},
    region: {},
  });

  const graphOption = {
    options: {
      dataLabels: {
        formatter: function (val) {
          return val + " %";
        },
      },
      grid: {
        show: false,
      },
      plotOptions: {
        bar: {
          horizontal: true,
          barHeight: "70%",
          dataLabels: {
            position: "center",
            style: {
              colors: ["#3433"],
            },
            enabled: true,
          },
        },
      },
      chart: {
        id: "basic-bar",
        toolbar: {
          show: false,
        },
        tools: {
          download: false,
        },
      },
      xaxis: {
        type: "Rating",
        categories: [10, 9, 8, 7, 6, 5, 4, 3, 2, 1],
      },
    },
  };

  const items = [
    {
      value: "1",
      label: "Menu 1",
      children: [
        {
          value: "11",
          label: "Another Item",
        },
        {
          value: "12",
          label: "More Items",
          children: [
            {
              value: "121",
              label: "Sub Item A",
            },
            {
              value: "122",
              label: "Sub Item B",
              disabled: true,
            },
            {
              value: "123",
              label: "Sub Item C",
            },
          ],
        },
      ],
    },
    {
      value: "2",
      label: "Menu 2",
    },
    {
      value: "3",
      label: "Menu 3",
      children: [
        {
          value: "31",
          label: "Hello",
        },
        {
          value: "21",
          label: "World",
        },
      ],
    },
  ];
  let options;
  useEffect(() => {
    // console.log(data.data.payload.ageAndGender,"data")
    setIt(
      data &&
      data.data &&
      Object.keys(data.data.payload.ageAndGender).map((m, i) => {
        return {
          value: m,
          label: m,
          children: Object.keys(data.data.payload.ageAndGender[m]).map((p) => {
            return {
              value: p,
              label: p,
            };
          }),
        };
      }));
    console.log(options);
  }, [data]);
  const handleClick = (e) => {
    e.stopPropagation();
    if (e.target.classList.contains("overall")) {
      if (filters.nofilters.overall !== undefined) {
        const obj = {};
        const obj1 = {};
        setFilters({ ...filters, nofilters: obj });
        setFiltersVotes({ ...filtersVotes, nofilters: obj1 });
      } else {
        settingOverall();
      }
      return;
    }
    const id = e.target.id;

    const elems = id.split(":");
    const elem = elems[0].split(",");
    const elem1 = elem[0];
    const elem2 = elem[1];

    const arrayone = Object.keys(data.data.payload[elem1][elem2].chartData);

    const arr = arrayone.map(
      (key) => data.data.payload[elem1][elem2].chartData[key].perc
    );
    arr.reverse();
    const obj = { ...filters[elem1], [elem2]: arr };

    const arraytwo = Object.keys(data.data.payload[elem1][elem2].chartData);
    const arr1 = arraytwo.map(
      (key) => data.data.payload[elem1][elem2].chartData[key].votes
    );
    arr1.reverse();
    const obj1 = { ...filtersVotes[elem1], [elem2]: arr1 };

    if (filters[elem1][elem2] !== undefined) {
      const a = { ...filters[elem1] };
      delete a[elem2];
      const b = { ...filtersVotes[elem1] };
      delete b[elem2];
      setFilters({ ...filters, [elem1]: a });
      setFiltersVotes({ ...filtersVotes, [elem1]: b });
    } else {
      setFilters({ ...filters, [elem1]: obj });
      setFiltersVotes({ ...filtersVotes, [elem1]: obj1 });
    }
  };

  const handleDelete = (e) => {
    if (e.target.classList.contains("overall")) {
      if (filters.nofilters.overall !== undefined) {
        const obj = {};
        setFilters({ ...filters, nofilters: obj });
        const obj1 = {};
        setFiltersVotes({ ...filtersVotes, nofilters: obj1 });
      } else {
        settingOverall();
      }
      return;
    }
    const val = e.target.className;
    for (let key in filters) {
      if (filters[key][val] !== undefined) {
        const obj = { ...filters[key] };

        delete obj[val];

        setFilters({ ...filters, [key]: obj });
        const obj1 = { ...filtersVotes[key] };
        delete obj1[val];
        setFiltersVotes({ ...filtersVotes, [key]: obj1 });
      }
    }
  };

  const settingOverall = () => {
    const arrayone = Object.keys(data.data.payload.global.chartData);
    const arr = arrayone.map(
      (key) => data.data.payload.global.chartData[key].perc
    );
    arr.reverse();
    const obj = { overall: arr };
    const arraytwo = Object.keys(data.data.payload.global.chartData);
    const arr1 = arraytwo.map(
      (key) => data.data.payload.global.chartData[key].votes
    );
    arr1.reverse();
    const obj1 = { overall: arr1 };

    setFilters({ ...filters, nofilters: obj });
    setFiltersVotes({ ...filtersVotes, nofilters: obj1 });
  };

  const handleEnter = (e) => {
    e.target.click();
  };
  useEffect(() => {
    setData(props.data);
  }, []);

  useEffect(() => {
    if (data) {
      settingOverall();
    }
  }, [data]);

  console.log(data ? data.data.payload : "");
  const notify = () => {
    navigator.clipboard.writeText(window.location.href);
    toast("Copied to clipboard");
  };

  return (
    <div>
      <ToastContainer />

      {data ? (
        <h4 className="heading">
          {data.data.payload.poll.question}
          <span onClick={notify}>
            Share result{" "}
            <i style={{ color: "#84855d" }} className="fas fa-share-alt"></i>
          </span>
        </h4>
      ) : (
        ""
      )}

      <div className="dropdowns">
        {/* <Dropdown className="d-inline mx-2" autoClose="outside">
          <Dropdown.Toggle
            id="dropdown-autoclose-outside"
            onMouseEnter={handleEnter}
            style={{ backgroundColor: "#84855D" }}
          >
            No Filter
          </Dropdown.Toggle>
          <Dropdown.Menu> */}
        <Dropdown.Item
          style={{ backgroundColor: "#84855D" }}
          className="overall"
          id="over"
          onClick={handleClick}
        >
          Overall
        </Dropdown.Item>
        {/* </Dropdown.Menu>
        </Dropdown> */}
        <DropdownCascade
          customStyles={{
            dropdown: {
              style: {
                margin: "5px 20px 15px 20px",
                color:"black"
              },
            },
          }}
          items={it?it:[]}
          onSelect={(value, selectedItems) => {
            console.log(value, selectedItems);
            setDropdownValue(value);
          }}
          
          value={dropdownValue}
        />
        <Dropdown className="d-inline mx-2" autoClose="outside">
          <Dropdown.Toggle
            id="dropdown-autoclose-outside"
            onMouseEnter={handleEnter}
            style={{ backgroundColor: "#84855D" }}
          >
            Gender
          </Dropdown.Toggle>

          <Dropdown.Menu>
            {data
              ? Object.keys(data.data.payload.gender).map((value, key) => (
                  <Dropdown.Item
                    key={key}
                    id={"gender," + value + ":" + key}
                    className={value}
                    onClick={handleClick}
                  >
                    {value}{" "}
                    <FiCheck id={"check," + value} className={"check"} />
                  </Dropdown.Item>
                ))
              : ""}
          </Dropdown.Menu>
        </Dropdown>

        <Dropdown className="d-inline mx-2" autoClose="outside">
          <Dropdown.Toggle
            id="dropdown-autoclose-outside"
            onMouseEnter={handleEnter}
            style={{ backgroundColor: "#84855D" }}
          >
            Age Groups
          </Dropdown.Toggle>

          <Dropdown.Menu>
            {data
              ? Object.keys(data.data.payload.age).map((value, key) => (
                  <Dropdown.Item
                    key={key}
                    id={"age," + value + ":" + key}
                    className={value}
                    onClick={handleClick}
                  >
                    {value}{" "}
                    <FiCheck id={"check," + value} className={"check"} />
                  </Dropdown.Item>
                ))
              : ""}
          </Dropdown.Menu>
        </Dropdown>

        <Dropdown className="d-inline mx-2" autoClose="outside">
          <Dropdown.Toggle
            style={{ backgroundColor: "#84855D" }}
            id="dropdown-autoclose-outside"
            onMouseEnter={handleEnter}
          >
            Region
          </Dropdown.Toggle>

          <Dropdown.Menu>
            {data
              ? Object.keys(data.data.payload.region).map((value, key) => (
                  <Dropdown.Item
                    key={key}
                    id={"region," + value + ":" + key}
                    className={value}
                    onClick={handleClick}
                  >
                    {value}{" "}
                    <FiCheck id={"check," + value} className={"check"} />
                  </Dropdown.Item>
                ))
              : ""}
          </Dropdown.Menu>
        </Dropdown>
      </div>

      <div className="fills">
        {Object.keys(filters).map((value, key) => {
          return Object.keys(filters[value]).map((val, idx) => {
            return (
              <span
                key={idx}
                className={val}
                id="selected"
                onClick={handleDelete}
              >
                {val} <FiXCircle />
              </span>
            );
          });
        })}
      </div>

      <div className="sub1">
        {Object.keys(filters).map((value, key) =>
          Object.keys(filters[value]).length > 0 ? (
            <>
              <h5>{value !== "nofilters" ? value : ""}</h5>
              <div key={key} className="box">
                {Object.keys(filters[value]).map((val, idx) => (
                  <div key={idx} className="group">
                    <Chart
                      className="bar1"
                      key={idx}
                      options={{
                        ...graphOption.options,
                        title: {
                          text: val !== "overall" ? val : "",
                          align: "left",
                        },
                      }}
                      series={[{ name: "Actual", data: filters[value][val] }]}
                      type="bar"
                      width="500"
                    />
                    <div className="votes">
                      <p className="bold">Votes</p>
                      {filtersVotes[value][val].map((val, idx) => (
                        <p key={idx} className="vote">
                          {val}
                        </p>
                      ))}
                      {value !== "nofilters" ? (
                        <p className="total">
                          Total votes :{" "}
                          {data ? data.data.payload[value][val].totalVotes : ""}
                        </p>
                      ) : (
                        <p className="total">
                          Total votes :
                          {data ? data.data.payload.global.totalVotes : ""}
                        </p>
                      )}
                    </div>
                  </div>
                ))}
              </div>
            </>
          ) : (
            <></>
          )
        )}
      </div>
    </div>
  );
}

export default BarCharts;
